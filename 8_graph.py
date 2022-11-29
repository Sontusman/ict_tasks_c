import matplotlib.pyplot as plt
import numpy as np
file = open("/home/sofya/Рабочий стол/workspace_airport_delays/Информатика_C/8o.txt", 'r')
euler, runge_kutta = [], []
for line in file:
    a = line.strip().split(" ")
    mas_e = np.array(a[1:6])
    mas_r = np.array(a[10:15])
    mas_e, mas_r = np.asarray(mas_e, dtype="float"), np.asarray(mas_r, dtype="float")
    euler.append(mas_e)
    runge_kutta.append(mas_r)
file.close()
euler, runge_kutta = np.array(euler), np.array(runge_kutta)
plt.scatter(euler[:, 4:5], euler[:, :1])
plt.scatter(euler[:, 4:5], euler[:, 1:2])
plt.scatter(euler[:, 4:5], euler[:, 2:3])
plt.scatter(euler[:, 4:5], euler[:, 3:4])
plt.scatter(runge_kutta[:, 4:5], runge_kutta[:, :1])
plt.scatter(runge_kutta[:, 4:5], runge_kutta[:, 1:2])
plt.scatter(runge_kutta[:, 4:5], runge_kutta[:, 2:3])
plt.scatter(runge_kutta[:, 4:5], runge_kutta[:, 3:4])
plt.xlim(0, 40)
plt.ylim(-1, 1)
plt.show()