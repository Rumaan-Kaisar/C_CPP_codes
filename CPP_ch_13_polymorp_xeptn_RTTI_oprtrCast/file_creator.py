
# import os

# Directory: List of the folders you want to create
file_names = [
    "ch13_01_pointers_derived_classes",
    "ch13_02_virtual_fn_abstract_class",
    "ch13_03_polymorphism",
    "ch13_04_generic_fn_class",
    "ch13_05_exception_handling",
    "ch13_06_exceptions_thrown_by_new",
    "ch13_07_rtti",
    "ch13_08_dynamic_cast",
    "ch13_09_const_reinterpret_static_casts"
]

# Parent Directory path
# parent_dir = "D:/Pycharm projects/GeeksForGeeks/Authors"

# Path
# path = os.path.join(parent_dir, directory)
for i in range (0, len(file_names)):
    # path = "./"+directories[i]
    # Create the files
    try:
        # os.makedirs(path, exist_ok = True)
        with open(f"{file_names[i]}.cpp", "w") as f:     # creates an empty 'c++'
            f.write("\n/*  ------------------------    chapter    ------------------------\n*/  \n")
        print(f"{file_names[i]}.cpp is created sucuessfully")
    except:
        print("files '%s' can not be created" % file_names[i])

# run windows cmd/terminal inside the working directory

# python file_creator.py

