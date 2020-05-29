import matplotlib.pyplot as plt
import numpy as np

dataset = np.loadtxt("datos.txt")

t = dataset[:,0]
y = dataset[:,1]

fig = plt.figure(figsize = (8,8))

ty = fig.add_subplot(211)
ty.scatter(t, y)
ty.set_xlabel("Tiempo (s)")
ty.set_ylabel("Altura (m)")