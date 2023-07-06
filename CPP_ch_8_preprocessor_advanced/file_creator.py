
# import os

# Directory: List of the folders you want to create
file_names = [
"C_Ch8_1_adv_define_include",
"C_Ch8_2_conDtnal_compile",
"C_Ch8_3_error_undef_line_pragma",
"C_Ch8_4_bultin_MACROS",
"C_Ch8_5_the_#_##_OpRTR",
"C_Ch8_6_func_pointers",
"C_Ch8_7_dynmic_allocation"
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
