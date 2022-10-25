"""для вызова плюсовой функции"""
from subprocess import Popen, PIPE

import subprocess
import os

def fit_from_c(population):

    p = Popen(['test.o'], shell=True, stdout=PIPE, stdin=PIPE)

    size_population = len(population)
    send(p, str(size_population))  # Отправка сообщения 1 
    
    """ Скорее всего отправка всей популяции не нужна, так как в алгоритмах
        фитнес функция принимает тоько одну особь и возвращает для нее значение
        следовательно в функцию С тоже надо отправлять одну особь и получать только
        её оценку 
    """
    for individual in population:

        #########################################################
        #   Блок преобразует вектор особи из списка вида        # 
        #   [x1,...,xn,y1,...,yn, ocenka]   в                   #
        #   строку вида "x1,...,xn;y1,...,yn"                   #
        indiv_x = individual[:int(len(individual)/2):]          #
        indiv_y = individual[int(len(individual)/2):-1:]        #
        indiv_x_str = ','.join([str(x) for x in indiv_x])       #  
        indiv_y_str = ','.join([str(y) for y in indiv_y])       #
        stroka = indiv_x_str + ';' + indiv_y_str                # 
        #########################################################
        
        send(p, stroka)  # Отправка сообщения строки особи

        result = p.stdout.readline().strip() # Считывание полученный строки
        mas = [float(x) for x in result.decode('utf-8').split(' ')]
        print(mas)

def send(pipe, value):
    "Функкция отправкии сообщений"
    value += '\n'
    value = bytes(value, 'utf-8')
    pipe.stdin.write(value)
    pipe.stdin.flush()


pop = [[1,2,3,4,5,6,7,8,1000],
        [10.123,11,12,13,14,15,16,17,5000],
        [20,21,22,23,24,25,26,27,6000]]



fit_from_c(pop)
