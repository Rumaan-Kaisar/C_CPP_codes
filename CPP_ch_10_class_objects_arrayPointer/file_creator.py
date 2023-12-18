
# import os

# Directory: List of the folders you want to create
file_names = [
    'ch10_01_1_class_intro',
    'ch10_01_2_constructor_destructor',
    'ch10_01_3_constructor_param',
    'ch10_02_inheritance_intro',
    'ch10_03_obj_pointer',
    'ch10_04_class_struct_union',
    'ch10_05_1_inLine_func',
    'ch10_05_2_auto_inLine',
    'ch10_06_1_assign_obj',
    'ch10_06_2_pass_obj_to_func',
    'ch10_06_3_return_obj_from_func',
    'ch10_07_friend_func',
    'ch10_08_1_array_of_obj',
    'ch10_08_2_pointer_to_obj',
    'ch10_09_1_this',
    'ch10_09_2_new_delete',
    'ch10_09_3_more_new_delete',
    'ch10_10_reference',
    'ch10_10_pass_ref_to_obj',
    'ch10_10_return_ref',
    'ch10_10_indpdnt_ref_&_rules'
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
