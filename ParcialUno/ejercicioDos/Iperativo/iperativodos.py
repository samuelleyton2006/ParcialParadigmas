def bubble_sort(students):
    n = len(students)
    for i in range(n - 1):
        swapped = False
        for j in range(n - 1 - i):
            # Separar lógica en pasos para mayor claridad
            should_swap = False  # Flag para decidir si se debe intercambiar
            
            # Paso 1: Comparar calificaciones
            if students[j][1] < students[j + 1][1]:
                should_swap = True
            # Paso 2: Si las calificaciones son iguales, comparar nombres
            elif students[j][1] == students[j + 1][1]:
                if students[j][0] > students[j + 1][0]:  # Comparar nombres
                    should_swap = True

            # Intercambiar si la bandera indica que se debe hacer
            if should_swap:
                students[j], students[j + 1] = students[j + 1], students[j]
                swapped = True
        
        # Si no hubo intercambio en esta pasada, la lista ya está ordenada
        if not swapped:
            break

# Lista de estudiantes (nombre, calificación)
students = [("Sam", 85), ("Samu", 92), ("Carl", 88), ("Carlos", 92), ("Anuel", 75)]

# Llamada a la función de ordenamiento usando Bubble Sort
bubble_sort(students)

# Imprimir la lista ordenada de estudiantes
print("Lista ordenada de estudiantes:", students)
