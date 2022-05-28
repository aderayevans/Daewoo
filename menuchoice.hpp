
enum class menuChoice
{
    quit,
    help,
    make,
    modify,
    blank,
    cancel,
    searchbyname,
    searchbydate,
    save,
    print,

    wrong
};

void printMenu();
menuChoice hashTheChoice(std::string choice);


void printMenu() 
{
    std::cout << R"(
**********                                              **********
syntax: -[Function]

[Function]:
    [q] or [quit] to quit the application
    [h] or [help] to print this menu
    [i] or [init] or [make] to make a reservation
    [m] or [modify] to modify a reservation
    [c] or [cancel] to cancel a reservation
    [s] or [save] to save
    [b] or [blank] to make blank
    [sm] or [searchbyname] to search reservations by name
    [sd] or [searchbydate] to search reservations by date of travel 
    
)";
}

menuChoice hashTheChoice(std::string choice)
{
    if (choice == "-q" || choice == "-quit")
        return menuChoice::quit;
    if (choice == "-h" || choice == "-help")
        return menuChoice::help;
    if (choice == "-i" || choice == "-init" || choice == "-make")
        return menuChoice::make;
    if (choice == "-m" || choice == "-modify")
        return menuChoice::modify;
    if (choice == "-c" || choice == "-cancel")
        return menuChoice::cancel;
    if (choice == "-s" || choice == "-save")
        return menuChoice::save;
    if (choice == "-p" || choice == "-print")
        return menuChoice::print;
    if (choice == "-b" || choice == "-blank")
        return menuChoice::blank;
    if (choice == "-sm" || choice == "-searchbyname")
        return menuChoice::searchbyname;
    if (choice == "-sd" || choice == "-searchbydate")
        return menuChoice::searchbydate;

    return menuChoice::wrong;
}