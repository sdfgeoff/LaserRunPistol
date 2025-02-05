import FreeCAD
import sys
import os
import MeshPart
import Mesh


    

try:
    args = sys.argv[sys.argv.index("--")+1:]

    input_filename = args[0]
    output_filename = args[1]

    print("Opening {}".format(input_filename))
    doc = FreeCAD.open(input_filename)

    clean_filename = os.path.basename(input_filename).replace(".FCStd", "")
    output_format = output_filename.split(".")[-1]

    stl_objects = []
    for obj in doc.Objects:
        if obj.Label.endswith(output_format):
            stl_objects.append(obj)

    if len(stl_objects) == 0:
        raise Exception(f"No objects ending in '{output_format}' present in file")
    if len(stl_objects) != 1:
        raise Exception(f"For build reproducibility, there can only be exactly one object ending in '{output_format}' in the freecad file. Found {list(o.Label for o in stl_objects)}")

    obj = stl_objects[0]

    if output_format == "stl":
        shape = obj.Shape
        # Would be nice to just export the file as STL but this uses (inconsistent)
        # view settings, so isn't reliable at producing smooth arcs etc.
        # shape.exportStl(output_filename)
        msh = FreeCAD.ActiveDocument.addObject("Mesh::Feature", "Mesh")

        msh.Mesh = MeshPart.meshFromShape(
            Shape=shape, 
            LinearDeflection=0.01, 
            AngularDeflection=0.0872665
        )
        print("Exporting to {}".format(output_filename))
        Mesh.export([msh], output_filename)
    
    elif output_format == "step":
        # Export the object as a step file
        print("Exporting to {}".format(output_filename))
        obj.Shape.exportStep(output_filename)


        
    exit(0)
except Exception as e:
    print(e)
    sys.stderr.write(str("--------- EXPORT ERROR: ---------\n"))
    sys.stderr.write(str(e))
    sys.stderr.write(str("\n---------------------------------\n"))

    exit(1)
