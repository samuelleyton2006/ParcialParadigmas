def bubble_sort(students):
    n = len(students)
    for i in range(n):
        swapped = False
        for j in range(0, n - i - 1):
            # Ordenar por calificación y luego por nombre en caso de empate
            if (students[j][1] < students[j + 1][1]) or (students[j][1] == students[j + 1][1] and students[j][0] > students[j + 1][0]):
                students[j], students[j + 1] = students[j + 1], students[j]
                swapped = True
        # Si no hubo intercambios, la lista está ordenada
        if not swapped:
            break

# Lista de estudiantes (nombre, calificación)
students = [("Sam", 85), ("Samu", 92), ("Carl", 88), ("Carlos", 92), ("Anuel", 75)]

# Llamada a la función de ordenamiento usando Bubble Sort
bubble_sort(students)

# Imprimir la lista ordenada de estudiantes
print("Lista ordenada de estudiantes:", students)
