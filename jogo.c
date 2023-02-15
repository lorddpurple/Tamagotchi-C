#include <stdio.h>
#include <stdlib.h>

typedef struct sat
{
    int health;
    int hungry;
    int poop;
    int sleep;
    int love;
    int typeanimal;

} Attributes;

typedef struct init
{





} Inicia;

print_dog()
{

    printf("\t\t             __\n");
    printf("\t\t (\,--------'()'--o\n ");
    printf("\t\t  (_    ___    /~'\n " );
    printf("\t\t   (_)_)  (_)_)\n ");

}

print_cat()
{

    printf("\t\t  |\__/,|   (`\ \n");
    printf("\t\t  |_ _  |.--.) ) \n");
    printf("\t\t  ( T   )     / \n");
    printf("\t\t (((^_(((/(((_/ \n");

}

print_fish()
{
    printf("\t\t\t   _ \n");
    printf("\t\t\t ><_> \n");
}

print_cow()
{

    printf("\t\t             (__) \n");
    printf("\t\t     `\------(oo) \n");
    printf("\t\t       ||    (__) \n");
    printf("\t\t       ||w--|| \n");


}

print_kill(){

printf(
                "\t\t        .\n"
                "\t\t       -|-\n"
                "\t\t        |\n"
                "\t\t    .-'~~~-.\n"
                "\t\t  .'         .\n"
                "\t\t  |  R  I  P  |\n"
                "\t\t  |           |\n"
                "\t\t  |           |\n"
                " \t\t \\|           |/\n"
                "\t\t-----------------*-*-\n"
                );

}

get_animal(int a)
{

    switch(a)
    {

    case 1:
        print_dog();
        break;

    case 2:
        print_cat();
        break;

    case 3:
        print_fish();
        break;

    case 4:
        print_cow();
        break;

    default:
        printf("\nCOLOCA UM BICHO PORRA\n");

    }

}

int menu(Attributes animal)
{

    int option;


    do
    {
        system("cls");

        printf(
            " ---------------------------------------------------------------------\n"
            "| SAUDE %d%% |  FOME %d%%  |  CAGAR %d%%  |  SONO %d%% |  AFETO %d%% |\n"
            " ---------------------------------------------------------------------\n\n",
            animal.health,
            animal.hungry,
            animal.poop,
            animal.sleep,
            animal.love

        );

        if(!death(animal)){

          get_animal(animal.typeanimal);

        }


        printf(
            "\n"
            " ----------- ------------- ------------- -------------\n"
            "| 1.BRINCAR  |  2.COMER   |  3.DORMIR   | 4.BANHEIRO  |\n"
            " ----------- ------------- ------------- -------------\n"
            "Escolha: "
        );

        scanf("%d", &option);
    }
    while(option < 0 || option > 5);

    return option;
}

play(Attributes *animal)
{

    if(animal->sleep < 70)
    {

        animal->hungry += 5;
        animal->sleep += 10;
        animal->love += 1;
        animal->poop += 1;

    }

    if(animal->hungry > 100)   animal->hungry = 100;

    if((animal->sleep) > 100)  animal->sleep = 100;

    if((animal->love) > 100)  animal->love = 100;

    if((animal->poop) > 100)  animal->poop = 100;

}

eat(Attributes *animal)
{

    Attributes buffer = *animal;


    if(animal->hungry > 0)
    {

        animal->hungry -= 10;
        animal->sleep += 5;
        animal->love += 1;
        animal->poop += 5;

    }

    if(animal->hungry < 0)   animal->hungry = 0;

    if((animal->sleep) > 100)  animal->sleep = 100;

    if((animal->love) > 100)  animal->love = 100;

    if((animal->poop) > 100)  animal->poop = 100;



}

sleeping(Attributes *animal)
{

    if(animal->sleep > 0)
    {

        animal->hungry += 10;
        animal->sleep -= 15;
        animal->poop += 10;

    }

    if(animal->hungry > 100)   animal->hungry = 100;

    if((animal->sleep) < 0)  animal->sleep = 0;

    if((animal->poop) > 100)  animal->poop = 100;


}

pooping(Attributes *animal)
{

    if(animal->sleep > 0)
    {

        animal->hungry += 5;
        animal->sleep += 5;
        animal->poop -= 50;

    }

    if(animal->hungry > 100)   animal->hungry = 100;

    if((animal->sleep) > 100)  animal->sleep = 100;

    if((animal->poop) < 0)  animal->poop = 0;


}

int death(Attributes animal){

    if(animal.health == 0 || animal.hungry == 100 || animal.poop == 100 || animal.sleep == 100 || animal.love == 0){

        print_kill();
        printf("\n\n\t\tO bicho morreu, seu malvado");
        return 1;

    }
    return 0;

}

void main ()
{

    Attributes animal;

    int op;

    animal.health = 100;
    animal.hungry =   0;
    animal.love = 1;
    animal.poop = 0;
    animal.sleep = 0;
    animal.typeanimal = 2;

    do
    {
        op = menu(animal);
        switch(op)
        {
        case 1:
            play(&animal);
            break;

        case 2:
            eat(&animal);
            break;

        case 3:
            sleeping(&animal);
            break;

        case 4:
            pooping(&animal);
            break;
        }


    }
    while(op !=0 );




}
