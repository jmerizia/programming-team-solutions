#!/usr/bin/env python3
import sys, argparse, os, re, time
from subprocess import call

COMPILE_FLAGS = "-fsanitize=address -std=c++14 -Wall"
BE_FANCY = False
LIB_DIR = "./library/"
TIME_COMMAND = "/usr/bin/time"
TIME_FORMAT = """
# real %e
# user %U
# sys %S
"""
TERM_HEIGHT, TERM_WIDTH = map(int, os.popen("stty size", "r").read().split())

parser = argparse.ArgumentParser(description='C++ Singleton Helper.')
parser.add_argument('fname', type=str)
parser.add_argument('-i', type=str, metavar='INPUT,FILES', help='comma separated input files')

args = parser.parse_args()
fname = args.fname
if args.i:
    input_files = [x.strip() for x in args.i.split(',')]
else:
    input_files = None


while True:
    code = ""
    orig = ""
    prev_indent = 0
    openings = 0
    opened_class = False
    # from https://gist.github.com/ChunMinChang/88bfa5842396c1fbbc5b
    def commentRemover(text):
        def replacer(match):
            s = match.group(0)
            if s.startswith('/'):
                return " " # note: a space and not an empty string
            else:
                return s
        pattern = re.compile(
            r'//.*?$|/\*.*?\*/|\'(?:\\.|[^\\\'])*\'|"(?:\\.|[^\\"])*"',
            re.DOTALL | re.MULTILINE
        )
        return re.sub(pattern, replacer, text)

    # Process code file, adding parenthesis and semicolons as needed
    with open(fname, 'r') as f:
        snippets_line = f.readline()
        orig += snippets_line
        snippet_files = [LIB_DIR + x.strip() for x in snippets_line.split(',')]
        line_idx = 2
        for line in f:
            orig += line
            if not BE_FANCY:
                code += line
                continue
            stripped = commentRemover(line).strip()

            if len(stripped) == 0:
                continue

            indent = len(line) - len(line.lstrip())
            indent_str = " "*indent
            prev_indent_str = " "*prev_indent
            
            # comment:
            if stripped.find('//') == 0:
                continue;

            # skip class block until back at 0 indentation
            if opened_class:
                if indent == 0:
                    opened_class = False
                code += line
                continue

            # class definition 
            if stripped.find('class') == 0:
                opened_class = True
                code += line
                continue

            if indent > prev_indent:
                if indent - 4 != prev_indent:
                    print("# Indentation issue ({} to {}), line {}".format(prev_indent, indent,
                            line_idx))
                    quit()
                code += "\n" + prev_indent_str + "{"
                openings += 1
            elif indent < prev_indent:
                # I think this indentation should be allowed
                #if indent + 4 != prev_indent:
                #    print("Indentation issue, line {}".format(line_idx))
                #    quit()
                code += ";"
                a = indent
                b = prev_indent
                while a != b:
                    b -= 4
                    code += "\n" + " "*b + "}"
                    openings -= 1
                if opened_class and indent == 0:
                    print("here")
                    code += ';'
                    opened_class = False
            else:
                if line_idx > 2:
                    code += ';'

            code += "\n"

            # if begins with READ
            if stripped.find('READ ') == 0:
                new_line = "cin"
                # skip the first, it is READ
                for var in stripped.split(' ')[1:]:
                    new_line += " >> {}".format(var.strip())
                code += indent_str + new_line

            # if begins with PRINT
            elif stripped.find('PRINTF ') == 0:
                new_line = "printf("
                start = stripped.find(' ') + 1
                new_line += stripped[start:] + ")"
                code += indent_str + new_line

            elif stripped.find('PRINT ') == 0:
                new_line = "cout << "
                start = 6
                new_line += stripped[start:]
                code += indent_str + new_line

            elif stripped.find('PRINTLN ') == 0:
                new_line = "cout << "
                start = 8
                new_line += stripped[start:]
                new_line += " << endl"
                code += indent_str + new_line

            elif stripped.find('if ') == 0:
                new_line = "if ("
                new_line += stripped[3:] + ")"
                code += indent_str + new_line
                
            else:
                code += indent_str + stripped

            line_idx += 1
            prev_indent = indent

        if BE_FANCY:
            code += ';'
            while openings > 1:
                openings -= 1
                code += "\n" + openings*4*" " + "}"
            code += "\n}"

    def get_snippet(fname):
        snippet = ""
        in_snippet = False
        with open(fname, 'r') as f:
            for line in f:
                if "snippet-end" in line:
                    in_snippet = False
                if in_snippet:
                    snippet += line
                if "snippet-begin" in line:
                    in_snippet = True
        return snippet

    snippets = ""
    for snippet_file in snippet_files:
        snippet_fname = "{}.cpp".format(snippet_file)
        snippets += get_snippet(snippet_fname)

    TEMP_FNAME = 'submit.cpp'
    final = snippets + code
    with open(TEMP_FNAME, 'w') as f:
        if BE_FANCY:
            f.write("/* pseudo-code:\n")
            for line in orig.split('\n'):
                f.write(' * ')
                f.write(line)
                f.write('\n')
            f.write(' */\n')
        f.write(final)

    # compile:
    print("# Compiling {}...".format(TEMP_FNAME))
    error_comp = False
    rc = os.system("g++ {} {} -o {}.out".format(TEMP_FNAME, COMPILE_FLAGS, TEMP_FNAME))
    if rc != 0: # compilation failed
        print("# Error compiling")
        error_comp = True

    # don't remove, we need to submit it!
    # os.remove(TEMP_FNAME)

    if not error_comp:
        # execute:
        print("# Executing {}...".format(TEMP_FNAME))
        error_exec = False
        if input_files:
            for input_file in input_files:
                print("# test {}:".format(input_file))
                rc = os.system("{} -p -f \"{}\" ./{}.out < {}".format(TIME_COMMAND, TIME_FORMAT, TEMP_FNAME, input_file))
                if rc != 0: # execution failed
                    print("# Error executing")
                    error_exec = True
        else:
            rc = os.system("{} -p -f \"{}\" ./{}.out".format(TIME_COMMAND, TIME_FORMAT, TEMP_FNAME))
            if rc != 0: # execution failed
                print("# Error executing")
                error_exec = True

        if not error_exec:
            os.remove("{}.out".format(TEMP_FNAME))

    # Check for updates
    print("# Waiting for updates...")
    while True:
        updated = False
        orig_now = ""
        with open(fname, 'r') as f:
            for line in f:
                orig_now += line
        snippets_now = ""
        for snippet_file in snippet_files:
            snippet_fname = "{}.cpp".format(snippet_file)
            snippets_now += get_snippet(snippet_fname)
        if orig == orig_now and snippets == snippets_now:
            time.sleep(0.5)
        else:
            print("# Change found!")
            break
