// определяет структуру in_addr
#include <arpa/inet.h>


// содержит константы и структуры
// нужен для адресов интернет-доменов
#include <netinet/in.h>


// стандартная библиотека ввода и вывода
#include <stdio.h>


// содержит строковые функции
#include <string.h>


// для создания сокета
#include <sys/socket.h>


// содержит конструкции, облегчающие получение
// информация об атрибутах файлов.
#include <sys/stat.h>


// содержит ряд основных производных типов
// это следует использовать при необходимости
#include <sys/types.h>


main()
{

    struct sockaddr_in client;

    int s, flag;

    char buffer[20];



    // создание сокета

    s = socket(AF_INET, SOCK_STREAM, 0);



    // назначаем IP, PORT

    client.sin_family = AF_INET;

    client.sin_port = 2000;

    client.sin_addr.s_addr = inet_addr("127.0.0.1");



    // подключаем сокет клиента к сокету сервера

    connect(s, (struct sockaddr*)&client, sizeof client);



    for (;;) {

        printf("\nEnter a string to check palindrome: ");

        scanf("%s", buffer);



        printf("\nClient: %s", buffer);

        send(s, buffer, sizeof(buffer), 0);

        recv(s, &flag, sizeof(int), 0);



        if (flag == 1) {

            printf("\nServer: The string is a Palindrome.\n");

            break;

        }

        else {

            printf("\nServer: The string is not a palindrome.\n");

            break;

        }

    }
    // закрываем сокет

    close(s);

}
