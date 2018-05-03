# mbed SDK
# Copyright (c) 2011-2016 ARM Limited
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

from os.path import join, exists, realpath, relpath, basename, isfile, splitext
from os import makedirs, listdir
import json

from tools.export.makefile import Makefile, GccArm, Armc5, IAR

class VSCode(Makefile):
    """Generic VSCode project. Intended to be subclassed by classes that
    specify a type of Makefile.
    """
    def generate(self):
        """Generate Makefile and VSCode launch and task files
        """
        super(VSCode, self).generate()
        ctx = {
            'name': self.project_name,
            'elf_location': join('BUILD', self.project_name)+'.elf',
            'c_symbols': self.toolchain.get_symbols(),
            'asm_symbols': self.toolchain.get_symbols(True),
            'target': self.target,
            'include_paths': self.resources.inc_dirs,
            'load_exe': str(self.LOAD_EXE).lower()
        }

        if not exists(join(self.export_dir, '.vscode')):
            makedirs(join(self.export_dir, '.vscode'))

        self.gen_file('vscode/tasks.tmpl', ctx,
                      join('.vscode', 'tasks.json'))
        self.gen_file('vscode/launch.tmpl', ctx,
                      join('.vscode', 'launch.json'))
        self.gen_file('vscode/settings.tmpl', ctx,
                      join('.vscode', 'settings.json'))

        # So.... I want all .h and .hpp files in self.resources.inc_dirs
        all_directories = []

        for directory in self.resources.inc_dirs:
            if not directory:
                continue

            if directory == ".":
                all_directories.append("${workspaceRoot}/*")
            else:
                all_directories.append(directory.replace("./", "${workspaceRoot}/") + "/*")

        cpp_props = {
            "configurations": [
                {
                    "name": "Windows",
                    "includePath": [x.replace("/", "\\") for x in all_directories]
                },
                {
                    "name": "Mac",
                    "includePath": all_directories
                },
                {
                    "name": "Linux",
                    "includePath": all_directories
                }
            ]
        }

        with open(join(self.export_dir, '.vscode', 'c_cpp_properties.json'), 'w') as outfile:
            json.dump(cpp_props, outfile, indent=4, separators=(',', ': '))


class VSCodeGcc(VSCode, GccArm):
    LOAD_EXE = True
    NAME = "VSCode-GCC-ARM"

class VSCodeArmc5(VSCode, Armc5):
    LOAD_EXE = True
    NAME = "VSCode-Armc5"

class VSCodeIAR(VSCode, IAR):
    LOAD_EXE = True
    NAME = "VSCode-IAR"


