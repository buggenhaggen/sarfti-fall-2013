#!/usr/bin/python

import subprocess

ret = subprocess.call("python ./AKorezin/task_2/helloworld.py", shell=True)
if ret:
    return ret


return ret
