def quick_sort(students):
    if len(students) <= 1:
        return students
    else:
        # Elegimos el pivote como el último elemento de la lista
        pivot = students[-1]
        # Dividimos en dos listas: mayores y menores al pivote
        left = [student for student in students[:-1] if student[1] > pivot[1] or (student[1] == pivot[1] and student[0] < pivot[0])]
        right = [student for student in students[:-1] if student[1] < pivot[1] or (student[1] == pivot[1] and student[0] >= pivot[0])]
        # Recursión para ordenar las sublistas
        return quick_sort(left) + [pivot] + quick_sort(right)

# Lista de estudiantes (nombre, calificación)
students = [("Sam", 85), ("Samu", 92), ("Carl", 88), ("Carlos", 92), ("Anuel", 75)]

# Llamada a la función de ordenamiento usando Quick Sort
sorted_students = quick_sort(students)

# Imprimir la lista ordenada de estudiantes
print("Lista ordenada de estudiantes:", sorted_students)

