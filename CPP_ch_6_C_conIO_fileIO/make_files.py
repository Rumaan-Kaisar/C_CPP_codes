# import os

# Directory: List of the folders you want to create
file_names = ["C_Ch6_1_1_mcro_sbt_define",
"C_Ch6_1_2_sdt_conio_gtCr_ptCr",
"C_Ch6_1_3_NONsdt_conio_gtCh_",
"C_Ch6_1_4_mstr_gets_puts",
"C_Ch6_1_5_mstr_printf",
"C_Ch6_1_6_mstr_scanf",
"C_Ch6_2_1_filio_strm",
"C_Ch6_2_2_file_access",
"C_Ch6_2_3_feof_ferror",
"C_Ch6_2_4_stringIO_filio",
"C_Ch6_2_5_BinaryIO",
"C_Ch6_2_6_RanAcss_fseek",
"C_Ch6_2_7_other_filio_func",
"C_Ch6_2_8_std_strm"]

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

