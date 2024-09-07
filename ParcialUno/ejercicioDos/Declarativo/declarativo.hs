-- Lista de estudiantes con sus calificaciones
students :: [(String, Int)]
students = [("Sam", 45), ("Samu", 32), ("Samue", 88), ("Carl", 92), ("Carlo", 75)]

-- Ordenar estudiantes por calificación (descendente) y luego por nombre (alfabéticamente)
sortStudents :: [(String, Int)] -> [(String, Int)]
sortStudents = sortBy compareStudents
  where
    compareStudents (name1, grade1) (name2, grade2)
      | grade1 > grade2 = LT
      | grade1 < grade2 = GT
      | otherwise       = compare name1 name2

-- Imprimir la lista ordenada
main :: IO ()
main = print (sortStudents students)
