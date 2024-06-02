# Questo script mostra una strada possibile per 
# "plottare" i tempi dei nostri esperimenti.

# Libreria per stampare il plot.
import matplotlib.pyplot as plt

# Prendo ogni riga dal file coi tempi degli esperimenti.
with open("report.txt") as file:
    lines = file.readlines()

# Algoritmi che sto considerando.
algos = ["INSERTION", "MERGE", "HYBRIDMERGE", "QUICK", "MOTQUICK", "TAILQUICK"]

# Prendo l'asse delle x (la prima riga del file coi tempi).
x_data = list(map(int, lines[0].split()))

# Prendo l'asse delle y (i tempi) per ogni algoritmo,
# ovvero tutte le righe dopo la primissima nel file coi tempi.
y_data = [list(map(float, line.split())) 
          for line in lines[1:]]

# Per ogni asse delle y, disegno su un grafico comune
# tutti i tempi (x,y), ovvero (dimensione, tempo-in-secondi).
# `i`, restituito da `enumerate`, mi permette di associare 
# una stringa in `algos` ai tempi che sto stampando.
for i, time in enumerate(y_data):
    plt.plot(x_data, time, label=algos[i])

# Rendo più bello il plot.
plt.xlabel("Size")
plt.ylabel("Elapsed time [s]")
plt.title("Sorting experiments")
plt.legend()
plt.show()