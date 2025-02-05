import os
import sys
import subprocess
from tempfile import TemporaryDirectory

HERE = os.path.dirname(os.path.abspath(__file__))

FREECAD_BINARY = "freecadcmd"
EXPORT_SINGLE_FILENAME = os.path.join(HERE, "./export_freecad_internal.py")

# Tup doesn't allow leaving behind temporary files, so we need a temporary folder for our python code so that pycache files are cleaned up properly
with TemporaryDirectory() as temp_dir:
    script_path = os.path.join(temp_dir, "export_stl_internal.py")
    with open(EXPORT_SINGLE_FILENAME, "r") as f:
        with open(script_path, "w") as g:
            g.write(f.read())

    in_file_path = sys.argv[1]
    out_file_path = sys.argv[2]

    command = [
        FREECAD_BINARY, 
        "-c", 
        script_path, 
        "--",
        in_file_path, 
        out_file_path,
    ]
    print(' '.join(command))
    try:
        subprocess.run(command, check=True)
    except:
        exit(1)
    
