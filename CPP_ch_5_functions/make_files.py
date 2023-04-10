# import os

# Directory: List of the folders you want to create
file_names = ["C_Ch5_1_1_func_potyp",
"C_Ch5_2_1_recrsn",
"C_Ch5_3_1_func_param",
"C_Ch5_3_2_main_param",
"C_Ch5_3_3_old_styl_param"]

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

