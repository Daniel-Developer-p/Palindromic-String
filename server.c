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

    struct sockaddr_in client, server;

    int s, n, sock, g, j, left, right, flag;

    char b1[20], b2[10], b3[10], b4[10];



    // создаем сокет

    s = socket(AF_INET, SOCK_STREAM, 0);



    // назначаем IP, PORT

    server.sin_family = AF_INET;



    // это номер порта работающего сервера

    server.sin_port = 2000;

    server.sin_addr.s_addr = inet_addr("127.0.0.1");



    // Привязка вновь созданного сокета

    // на указанный IP и подтверждение

    bind(s, (struct sockaddr*)&server, sizeof server);

    listen(s, 1);

    n = sizeof client;



    sock = accept(s, (struct sockaddr*)&client, &n);

    for (;;) {

        recv(sock, b1, sizeof(b1), 0);



        // всякий раз, когда приходит запрос от клиента.

        // Это будет обработано здесь.

        printf("\nThe string received is:%s\n", b1);

        if (strlen(b1) == 0)

            flag = 1;

        else {

            left = 0;

            right = strlen(b1) - 1;

            flag = 1;

            while (left < right && flag) {

                if (b1[left] != b1[right])

                    flag = 0;

                else {

                    left++;

                    right--;

                }

            }

        }

        send(sock, &flag, sizeof(int), 0);

        break;

    }

    close(sock);

    // закрываем сокет

    close(s);

}
