#include <iostream>
#include <vector>
#include <string>

using std::vector;


vector<double> get_individ()  // функция, считывающая строку вида "x1,...,xn;y1,...,yn". 
                              // преобразует её в вектор вида {x1,y1,...,xn,yn}
{   
    vector<double> res;

    vector<double> x_mas;
    vector<double> y_mas;

    bool flag = true;
    std::string stroka;
    std::string tmp_stroka = "";

    int len;

    std::cin >> stroka;
    len = stroka.length();
    for (int i=0; i<len; ++i )
    {   
        if (stroka[i]==';')
        {   
            flag = false;
            x_mas.push_back(std::stod(tmp_stroka));
            tmp_stroka = "";
        }

        if(stroka[i]==',' && flag == true)
        {
            x_mas.push_back(std::stod(tmp_stroka));
            tmp_stroka = "";
        }
        if(stroka[i]==',' && flag == false)
        {
            y_mas.push_back(std::stod(tmp_stroka));
            tmp_stroka = "";
        }

        if(stroka[i] != ',' && stroka[i] != ';')
            tmp_stroka += stroka[i];
    }
    y_mas.push_back(std::stod(tmp_stroka));

    len = x_mas.size(); 
    for (int i=0; i<len; i++ )
    {
           res.push_back(x_mas[i]);
           res.push_back(y_mas[i]);
    }

    //отправка в питон, чтобы посмотреть что получилось
    std::cout << res[0]<<" "<< res[1]<<" "<< res[2]<<" "<< res[3]<<" "<< res[4]<<" "<< res[5]<<" "<< res[6]<<" "<< res[7]<<" " << std::endl;
    std::cout.flush();
    return res;
}

void send(vector<double> ocenki) //функция отправляет сообщение
{
    std::string stroka = "";
    int len;
    len = ocenki.size();
    for (int i=0; i<len; ++i )
    {
        stroka += std::to_string(ocenki[i]);
    }
    std::cout << stroka << std::endl;
    std::cout.flush();

}

int main(){

    int size_pop;
    std::cin >> size_pop;  // Приём сообщения с количеством особей в популяции
    vector<vector<double>> population;

    for( int i=0; i<size_pop; ++i )
    {   
        population.push_back(get_individ());
    }

    // QVector<paint_ZZP*> nabor_ZZP = {}
    // paint_zona_puska zona_puska = {} 
    // paint_polygon_p sektor_zapuska = {}
    // QVector<double> params_of_task = {1,2,3,4,5,6}
    // procedure_ocenka(population, nabor_ZZP, zona_puska, sektor_zapuska, params_of_task)

    //send(ocenki)
    
    return 0;
}