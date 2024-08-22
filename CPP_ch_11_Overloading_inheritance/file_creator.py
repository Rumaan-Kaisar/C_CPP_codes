
# import os

# Directory: List of the folders you want to create
file_names = [
    'ch11_01_1_ovrld_constructor',
    'ch11_01_2_copy_constructor',
    'ch11_01_3_ovrld_anachronism',
    'ch11_02_default_args',
    'ch11_03_ovrld_ambiguity',
    'ch11_04_ovrld_address_function',
    'ch11_05_1_ovrldOpr_intro',
    'ch11_05_2_ovrldOpr_binary',
    'ch11_05_3_ovrldOpr_relational_logical',
    'ch11_05_4_ovrldOpr_unary',
    'ch11_06_ovrldOpr_friend',
    'ch11_07_ovrldOpr_assignment',
    'ch11_08_ovrldOpr_subscript_sqrBrc',
    'ch11_09_inhrit_BaseClass_access',
    'ch11_10_inhrit_protected_members',
    'ch11_11_inhrit_constructor_destructor',
    'ch11_12_inhrit_multi',
    'ch11_13_inhrit_virtualBase'
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

