# import os

# Directory: List of the folders you want to create
file_names = ["C_Ch4_1_3_initialize_array",
"C_Ch4_2_1_strings",
"C_Ch4_2_2_string_array",
"C_Ch4_3_1_pointer",
"C_Ch4_3_2_pointer_rules",
"C_Ch4_4_1_array_&_pointer",
"C_Ch4_4_2_string_&_pointer",
"C_Ch4_4_3_arrayOfpointer",
"C_Ch4_5_1_multi_indirectn",
"C_Ch4_5_2_param_pointer_arg"]

# Parent Directory path
# parent_dir = "D:/Pycharm projects/GeeksForGeeks/Authors"

# Path
# path = os.path.join(parent_dir, directory)
for i in range (0, len(file_names)):
    # path = "./"+directories[i]
    # Create the files
    try:
        # os.makedirs(path, exist_ok = True)
        f = open(f"{file_names[i]}.c", "w") # creates an empty 'c' 
        print(f"{file_names[i]}.c is created sucuessfully")
    except:
        print("files '%s' can not be created" % file_names[i])

# run windows cmd/terminal inside the working directory
# python make_files.py