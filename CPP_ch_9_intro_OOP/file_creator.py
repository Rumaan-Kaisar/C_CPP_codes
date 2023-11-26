
# import os

# Directory: List of the folders you want to create
file_names = [
"cpp_ch9_1_OOP_intro",
"cpp_ch9_2_old_vs_std_header",
"cpp_ch9_3_func_ovrld",
"cpp_ch9_4_comments",
"cpp_ch9_5_cpp_conio",
"cpp_ch9_6_c_vs_cpp",
"cpp_ch9_7_cpp_Kywrd"
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
        f = open(f"{file_names[i]}.cpp", "w") # creates an empty 'c++' 
        print(f"{file_names[i]} is created sucuessfully")
    except:
        print("files '%s' can not be created" % file_names[i])

# run windows cmd/terminal inside the working directory

# python file_creator.py

