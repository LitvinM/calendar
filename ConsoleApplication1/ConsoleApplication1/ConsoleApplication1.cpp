// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

//#include "TodoServerApp.h"



#include "crow.h"
#include "crow/middlewares/cors.h"
//#include "crow_all.h"

#include "string"
#include "vector"

using namespace std;

vector<string> addToVector(vector<string>& data, string str) {
    data.push_back(str);
    return data;
}


int main()
{
    crow::App<crow::CORSHandler> app;

    // Customize CORS
    auto& cors = app.get_middleware<crow::CORSHandler>();

    // clang-format off
    cors
        .global()
        .headers("X-Custom-Header", "Upgrade-Insecure-Requests", "Access-Control-Allow-Origin")
        .methods("POST"_method, "GET"_method, "DELETE"_method)
        .prefix("/cors")
        .origin("http://localhost:3000")
        .prefix("/nocors")
        .ignore();
    // clang-format on

    string test = "test";

    vector<vector<string>> data(31, vector<string>());
    
 
    //define your endpoint at the root directory
    CROW_ROUTE(app, "/")([data]() {
        crow::json::wvalue x;
        x["data"] = data;
        return x;
    });

    CROW_ROUTE(app, "/add/<int>")([&data](int day) {

        crow::json::wvalue x;
        x["data"] = data[day];
        return x;
    });

    CROW_ROUTE(app, "/add_json/<int>")
        .methods("POST"_method)
        ([&data](const crow::request& req,int day) {
        auto x = crow::json::load(req.body);


        data[day].push_back(x["message"].s());
        return "done";
            });

    CROW_ROUTE(app, "/delete/<int>/<int>")
        .methods("DELETE"_method)
        ([&data]( int day,int index) {
        
        auto iter = data[day].cbegin();
        data[day].erase(iter+index);
        return "done";
            });



    //set the port, set the app to run on multiple threads, and run the app
    app.port(18080).multithreaded().run();
}




// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
