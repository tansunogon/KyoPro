import subprocess
import shutil

data = [
	(
		"algorithm", ["sort", "max", "min", "lower_bound", "upper_bound"]
	),
	(
		"cassert", ["assert"]
	),
	(
		"climits", ["LLONG_MAX"]
	),
	(
		"climits", ["log", "exp"]
	),
	(
		"deque", ["deque"]
	),
	(
		"functional", ["function", "plus", "less", "greater"]
	),
	(
		"iostream", ["cin", "cout"]
	),
	(
		"numeric", ["gcd(", "gcd<"]
	),
	(
		"set", ["set"]
	),
	(
		"unordered_map", ["unordered_map"]
	),
	(
		"utility", ["swap", "move", "pair"]
	),
	(
		"vector", ["vector"]
	),
]

if False:
	res = subprocess.call('MSBuild')
	if res != 0:
		pass

# shutil.copyfile('KyoPro/main.cpp', 'main.back.cpp')

lines = None
with open('KyoPro/main.cpp', 'r', encoding='shift_jis') as f:
	lines = f.readlines()


includes = []
source = ""
for line in lines:
	if line.startswith("#include"):
		includes.append(line)
	else:
		source += line

necessary_includes = []
for header_name, def_list in data:
	if any(map(source.__contains__, def_list)):
		necessary_includes.append(f"#include <{header_name}>\n")

with open('KyoPro/main.cpp', 'w', encoding='shift_jis') as f:
	for line in necessary_includes:
		f.write(line)
	f.write(source)

print("end")
