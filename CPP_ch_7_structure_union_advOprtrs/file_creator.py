
# import os

# Directory: List of the folders you want to create
file_names = [
"C_Ch7_1_1_STRUCT",
"C_Ch7_1_2_STRUCT_pointer ",
"C_Ch7_1_3_nested_STRUCT",
"C_Ch7_2_1_Bit_fild",
"C_Ch7_2_2_UNION",
"C_Ch7_3_1_storz_cls_spcifyr",
"C_Ch7_3_2_acs_modfyr_constVolatile",
"C_Ch7_4_1_ENUMERATIONS",
"C_Ch7_4_2_typedef",
"C_Ch7_5_1_Bitwise_OpRTR",
"C_Ch7_5_2_Shift_OpRTR",
"C_Ch7_5_3_ternary_OpRTR",
"C_Ch7_5_4_adv_asigmnt_OpRTR",
"C_Ch7_5_5_Comma_OpRTR",
"C_Ch7_5_6_prcdns_of_OpRTR"
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
