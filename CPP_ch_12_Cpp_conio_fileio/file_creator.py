
# import os

# Directory: List of the folders you want to create
file_names = [
    "ch12_01_io_basics",
    "ch12_02_formatted_io",
    "ch12_03_width_precision_fill",
    "ch12_04_io_manipulators",
    "ch12_05_custom_inserters",
    "ch12_06_custom_extractors",
    "ch12_07_custom_manipulators",
    "ch12_08_file_io_basics",
    "ch12_09_unformatted_bin_io",
    "ch12_10_more_unformatted_io",
    "ch12_11_random_access",
    "ch12_12_io_status_check",
    "ch12_13_custom_io_files"
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
        print(f"{file_names[i]}.py is created sucuessfully")
    except:
        print("files '%s' can not be created" % file_names[i])

# run windows cmd/terminal inside the working directory

# python file_creator.py

