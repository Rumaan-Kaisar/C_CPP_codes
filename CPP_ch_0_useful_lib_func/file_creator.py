
# import os

# Directory: List of the folders you want to create
file_names = [
"C_Ch0_0_C_Keywords",
"C_Ch0_1_IO ",
"C_Ch0_2_Str_char",
"C_Ch0_3_Math",
"C_Ch0_4_Time ",
"C_Ch0_5_dyn_alloc",
"C_Ch0_6_Misc"
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
        f = open(f"{file_names[i]}.c", "w") # creates an empty 'c' 
        print(f"{file_names[i]}.c is created sucuessfully")
    except:
        print("files '%s' can not be created" % file_names[i])

# run windows cmd/terminal inside the working directory

# python file_creator.py


