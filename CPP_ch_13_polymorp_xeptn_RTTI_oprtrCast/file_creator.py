
# import os

# Directory: List of the folders you want to create
file_names = [
    "ch13_01_pointers_derived_classes",
    "ch13_02_intro_virtual_fn",
    "ch13_03_more_virtual_fn",
    "ch13_04_apply_polymorphism",
    "ch13_05_generic_fn",
    "ch13_06_generic_classes",
    "ch13_07_exception_handling",
    "ch13_08_more_exception_handling",
    "ch13_09_exceptions_thrown_by_new",
    "ch13_10_understanding_rtti",
    "ch13_11_dynamic_cast",
    "ch13_12_const_reinterpret_static_casts"
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

