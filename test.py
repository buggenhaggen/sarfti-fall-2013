#!/usr/bin/python

import subprocess
import sys

ret = subprocess.call("python ./AKorezin/task_3/helloworld.py", shell=True)
if ret:
    sys.exit(ret)


sys.exit(ret)
