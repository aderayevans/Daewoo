
enum class menuChoice_modify
{
    quit,
    help,
    back,
    modify_pas,
    modify_tic,


    wrong
};

void printMenu_modify();
menuChoice_modify hashTheChoice_modify(std::string choice);



void printMenu_modify() 
{
    std::cout << R"(
**********               Modification Menu               **********
syntax: -[Function]

[Function]:
    [q] or [quit] to quit the application
    [h] or [help] to print this menu
    [b] or [back] to go back the previous menu
    [p] or [passenger] to modify passenger infomations
    [t] or [ticket] to modify ticket (seat number)
    
)";
}

menuChoice_modify hashTheChoice_modify(std::string choice)
{
    if (choice == "-q" || choice == "-quit")
        return menuChoice_modify::quit;
    if (choice == "-h" || choice == "-help")
        return menuChoice_modify::help;
    if (choice == "-b" || choice == "-back" || choice == "-make")
        return menuChoice_modify::back;
    if (choice == "-p" || choice == "-passenger")
        return menuChoice_modify::modify_pas;
    if (choice == "-t" || choice == "-ticket")
        return menuChoice_modify::modify_tic;

    return menuChoice_modify::wrong;
}