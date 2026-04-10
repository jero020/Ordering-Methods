

Ordering Methods
Comparación de Algoritmos de Ordenamiento en C++

Jerónimo Vélez
Jerónimo Echeverry
Sebastian Roldan •  2025



1. Introducción
Este informe documenta la implementación y comparación de cuatro algoritmos clásicos de ordenamiento en C++: Bubble Sort, Insertion Sort, Quick Sort y Merge Sort. El objetivo es ordenar alfabéticamente un dataset de 100,000 palabras en formato .txt y medir el tiempo de ejecución de cada algoritmo para analizar su eficiencia en la práctica.

Todos los algoritmos trabajan sobre copias independientes del mismo dataset, garantizando una comparación justa. Los tiempos se midieron utilizando la biblioteca <chrono> de C++ en un MacBook Pro 16" (2019) con procesador Intel Core i7 de 2.6 GHz y 16 GB de RAM.

2. Estructura del Proyecto
El proyecto está organizado de la siguiente manera:

Ordering-Methods/
  Main.cpp              ← Punto de entrada, mide tiempos
  Leerdatos.h / .cpp    ← Lectura del dataset desde .txt
  FuncionesMetodos/
    BubbleSort.h / .cpp
    InsertionSort.h / .cpp
    QuickSort.h / .cpp
    MergeSort.h / .cpp

Cada algoritmo tiene su propio par .h / .cpp. El .h declara la firma de la función y el .cpp contiene la implementación. Esta separación permite que Main.cpp llame a cualquier algoritmo simplemente incluyendo su header, sin necesidad de conocer los detalles internos.

3. Lectura del Dataset — Leerdatos
3.1 Explicación del algoritmo
La función leerDatos se encarga de abrir el archivo .txt y convertir cada línea en un elemento del vector de strings. Este vector es luego copiado para cada algoritmo, garantizando que todos partan del mismo estado desordenado.

3.2 Código línea por línea

std::vector<std::string> leerDatos(const std::string& ruta) {
→ Recibe la ruta del archivo por referencia constante para evitar copias innecesarias. Retorna un vector de strings con todas las palabras.

    std::ifstream archivo(ruta);
→ Abre el archivo en modo lectura. ifstream (input file stream) es el tipo estándar de C++ para leer archivos.

    if (!archivo) throw std::runtime_error("No se puede abrir");
→ Si el archivo no existe o no puede abrirse, lanza una excepción que será capturada en main(). Esto evita que el programa continúe con datos vacíos.

    while (std::getline(archivo, linea)) {
→ Lee el archivo línea por línea. getline extrae caracteres hasta encontrar un salto de línea '\n', lo que permite procesar cada palabra individualmente.

        if (linea.back() == '\r') linea.pop_back();
→ Elimina el carácter \r si existe. Esto ocurre en archivos creados en Windows (formato \r\n) que al abrirse en macOS/Linux dejan ese carácter extra al final de cada línea.

        datos.push_back(linea);
→ Agrega la línea al vector. push_back inserta el elemento al final del vector, que crece dinámicamente en memoria.

4. Bubble Sort
4.1 Explicación del algoritmo
Bubble Sort es el algoritmo de ordenamiento más sencillo. Recorre el arreglo repetidamente comparando cada par de elementos adyacentes y los intercambia si están en el orden incorrecto. En cada pasada completa, el elemento más grande "burbujea" hasta el final del arreglo, como una burbuja que sube a la superficie.

Su principal desventaja es su complejidad O(n²), lo que lo hace muy lento para datasets grandes. Con 100,000 palabras realiza aproximadamente 5,000,000,000 comparaciones.

4.2 Código línea por línea

void bubbleSort(std::vector<std::string>& arr, int n) {
→ Recibe el vector por referencia (&) para modificarlo directamente sin copiar los 100,000 strings. El parámetro n indica el tamaño del arreglo.

    for (int i = 0; i < n - 1; i++) {
→ Bucle externo que controla el número de pasadas. Se necesitan n-1 pasadas en el peor caso para ordenar completamente el arreglo. Después de cada pasada i, los últimos i elementos ya están en su posición final.

        for (int j = 0; j < n - i - 1; j++) {
→ Bucle interno que compara elementos adyacentes. El límite es n-i-1 porque después de i pasadas, los últimos i elementos ya están ordenados y no necesitan compararse.

            if (arr[j] > arr[j + 1]) {
→ Compara dos strings adyacentes. El operador > en C++ compara strings carácter por carácter usando sus valores ASCII, lo que produce orden alfabético correcto.

                std::string temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
→ Intercambio clásico de tres pasos usando una variable temporal. Es necesario guardar arr[j] en temp antes de sobreescribirlo, de lo contrario se perdería su valor.

5. Insertion Sort
5.1 Explicación del algoritmo
Insertion Sort funciona de manera similar a como ordenamos cartas en la mano: tomamos una carta (elemento) y la insertamos en la posición correcta entre las cartas ya ordenadas. El arreglo se divide conceptualmente en una parte ordenada (izquierda) y una desordenada (derecha), y en cada iteración se toma el primer elemento desordenado y se inserta donde corresponde.

Su complejidad también es O(n²), pero tiene una ventaja importante: si el arreglo ya está casi ordenado, se comporta casi como O(n), siendo más eficiente que Bubble Sort en esos casos.

5.2 Código línea por línea

void insertionSort(std::vector<std::string>& arr) {
→ Recibe el vector por referencia para modificarlo en sitio. No necesita el parámetro n porque puede obtener el tamaño con arr.size().

    for (int i = 1; i < n; i++) {
→ Empieza desde el índice 1 porque el primer elemento (índice 0) se considera trivialmente ordenado. Cada iteración toma arr[i] e intenta colocarlo en el lugar correcto.

        std::string key = arr[i];
→ Guarda el elemento actual en key antes de que sea sobreescrito por los desplazamientos. key es el elemento que vamos a insertar en la posición correcta.

        int j = i - 1;
→ j apunta al último elemento de la parte ya ordenada. Usaremos j para recorrer hacia la izquierda buscando dónde insertar key.

        while (j >= 0 && arr[j] > key) {
→ Mientras haya elementos a la izquierda (j >= 0) y el elemento actual sea mayor que key, seguimos desplazando. Las dos condiciones evitan salirse del arreglo y determinan cuándo encontramos la posición correcta.

            arr[j + 1] = arr[j];
→ Desplaza el elemento una posición a la derecha, haciendo espacio para insertar key. Esto sobreescribe arr[i] original, por eso lo guardamos en key antes.

        arr[j + 1] = key;
→ Inserta key en su posición correcta. Cuando el while termina, j+1 es exactamente el índice donde debe ir key.

6. Quick Sort
6.1 Explicación del algoritmo
Quick Sort es uno de los algoritmos más eficientes en la práctica. Su estrategia es "divide y vencerás": elige un elemento llamado pivote y reorganiza el arreglo de modo que todos los elementos menores queden a su izquierda y todos los mayores a su derecha. Luego aplica el mismo proceso recursivamente a cada mitad.

Su complejidad promedio es O(n log n), pero en el peor caso (arreglo ya ordenado con pivote fijo) puede degradarse a O(n²). Para evitar esto se usa un pivote aleatorio.

6.2 Código línea por línea

int partition(std::vector<std::string>& arr, int low, int high) {
→ Función auxiliar que reorganiza el subarreglo entre los índices low y high, colocando el pivote en su posición definitiva. Retorna el índice final del pivote.

    int randomIdx = low + rand() % (high - low + 1);
→ Genera un índice aleatorio dentro del rango [low, high]. Usar pivote aleatorio evita el peor caso O(n²) que ocurre cuando el pivote siempre es el mínimo o máximo del subarreglo.

    std::swap(arr[randomIdx], arr[high]);
→ Mueve el pivote aleatorio al final del subarreglo. El resto del algoritmo asume que el pivote está en arr[high], por eso hacemos este intercambio primero.

    std::string pivot = arr[high];
→ Guarda el valor del pivote. Este es el elemento contra el cual compararemos todos los demás.

    int i = low - 1;
→ i es el índice del último elemento menor o igual al pivote. Empieza en low-1 (antes del inicio) porque aún no hemos encontrado ninguno.

    for (int j = low; j < high; j++) {
→ Recorre todos los elementos excepto el pivote (que está en high). Para cada elemento decide si va al lado izquierdo (menores) o derecho (mayores) del pivote.

        if (arr[j] <= pivot) { i++; std::swap(arr[i], arr[j]); }
→ Si el elemento es menor o igual al pivote, incrementa i y lo mueve al lado izquierdo mediante swap. Al final del bucle, todos los elementos en [low..i] son menores o iguales al pivote.

    std::swap(arr[i + 1], arr[high]);
→ Coloca el pivote en su posición definitiva (i+1). Esta es la posición exacta que le corresponde en el arreglo ordenado final — nunca volverá a moverse.

void quickSort(std::vector<std::string>& arr, int low, int high) {
→ Función principal recursiva. Es void porque modifica el vector por referencia directamente, sin necesidad de retornar copias.

    if (low < high) {
→ Caso base de la recursión: si low >= high el subarreglo tiene 0 o 1 elemento y ya está ordenado. Solo continuamos cuando hay 2 o más elementos.

        int pi = partition(arr, low, high);
→ Particiona el subarreglo y obtiene el índice final del pivote. Después de esta llamada, arr[pi] está en su posición definitiva.

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
→ Ordena recursivamente la mitad izquierda (elementos menores) y la mitad derecha (elementos mayores). El pivote no se incluye porque ya está en su lugar.

7. Merge Sort
7.1 Explicación del algoritmo
Merge Sort también usa "divide y vencerás" pero con una estrategia diferente: divide el arreglo en dos mitades iguales, las ordena recursivamente de forma independiente, y luego las fusiona (merge) en un solo arreglo ordenado. A diferencia de Quick Sort, siempre divide exactamente por la mitad, garantizando O(n log n) en todos los casos.

Su desventaja es que necesita memoria auxiliar (arreglos temporales L y R) proporcional al tamaño del arreglo, lo que lo hace más lento que Quick Sort en la práctica por las copias de memoria.

7.2 Código línea por línea

void merge(std::vector<std::string>& arr, int left, int mid, int right) {
→ Función auxiliar que fusiona dos subarreglos ya ordenados: [left..mid] y [mid+1..right]. El resultado es el segmento [left..right] completamente ordenado.

    std::vector<std::string> L(arr.begin()+left, arr.begin()+mid+1);
    std::vector<std::string> R(arr.begin()+mid+1, arr.begin()+right+1);
→ Crea copias temporales de las dos mitades. Es necesario copiar porque el proceso de fusión sobreescribe el arreglo original mientras lee de él.

    int i = 0, j = 0, k = left;
→ i recorre L, j recorre R, k es el índice de escritura en arr. Empezamos escribiendo desde left para no afectar elementos fuera del rango actual.

    while (i < n1 && j < n2) {
→ Mientras ambas mitades tengan elementos por procesar, comparamos el frente de cada una y tomamos el menor.

        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
→ El elemento menor va al arreglo resultado. Usamos <= para mantener la estabilidad del algoritmo (elementos iguales mantienen su orden relativo original).

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
→ Copia los elementos restantes de la mitad que no se agotó. Si L tiene más elementos que R o viceversa, estos loops vacían lo que queda.

void mergeSort(std::vector<std::string>& arr, int left, int right) {
→ Función principal recursiva. Es void porque modifica el vector por referencia. Recibe los índices left y right para trabajar sobre un subarreglo específico.

    int mid = left + (right - left) / 2;
→ Calcula el punto medio evitando overflow. La forma (left+right)/2 puede causar overflow de enteros para índices muy grandes; esta fórmula es más segura.

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
→ Ordena recursivamente cada mitad. Las llamadas continúan hasta llegar a subarreglos de 1 elemento (caso base: left >= right).

    merge(arr, left, mid, right);
→ Fusiona las dos mitades ya ordenadas. Esta llamada ocurre de abajo hacia arriba: primero se fusionan pares, luego grupos de 4, luego de 8, hasta tener el arreglo completo.

8. Main — Medición de Tiempos
8.1 Justificación del diseño
Para comparar los algoritmos de forma justa, cada uno recibe una copia independiente del dataset original. Si todos usaran el mismo vector, el segundo algoritmo recibiría datos ya ordenados por el primero, sesgando completamente los resultados.

8.2 Código línea por línea

std::vector<std::string> copia1 = datos;
std::vector<std::string> copia2 = datos;
std::vector<std::string> copia3 = datos;
std::vector<std::string> copia4 = datos;
→ Crea cuatro copias del vector original. Cada algoritmo trabaja sobre su propia copia desordenada, garantizando condiciones idénticas para todos.

auto start = std::chrono::high_resolution_clock::now();
→ Captura el tiempo actual con la máxima precisión disponible en el sistema. high_resolution_clock tiene resolución de nanosegundos, suficiente para medir diferencias de milisegundos.

quickSort(copia1, 0, copia1.size() - 1);
→ Llama al algoritmo pasando el índice 0 como inicio y size()-1 como final. Es crítico pasar size()-1 y no size()/2 para ordenar el arreglo completo.

auto end = std::chrono::high_resolution_clock::now();
std::chrono::duration<double, std::milli> duration = end - start;
→ Calcula la diferencia entre el tiempo final e inicial. El tipo duration<double, std::milli> expresa el resultado en milisegundos con precisión decimal.

std::cout << "Quick Sort tomó " << duration.count() << " ms" << std::endl;
→ Imprime el resultado. duration.count() retorna el valor numérico de la duración en las unidades especificadas (milisegundos en este caso).

9. Comparación de Tiempos de Ejecución
9.1 Resultados obtenidos
Los tiempos fueron medidos ordenando 100,000 palabras en un MacBook Pro 16" (2019), Intel Core i7 2.6 GHz, 16 GB RAM, macOS 26.3.1:

Algoritmo
Tiempo (ms)
Complejidad
Resultado
Quick Sort
223 ms
O(n log n)
Más rápido
Merge Sort
284 ms
O(n log n)
Segundo lugar
Insertion Sort
200,083 ms (~3.3 min)
O(n²)
Tercer lugar
Bubble Sort
En ejecución
O(n²)
Esperado más lento

9.2 Análisis de los resultados
Quick Sort vs Merge Sort
Ambos tienen la misma complejidad teórica O(n log n), pero Quick Sort fue un 21% más rápido. Esto se debe a que Quick Sort ordena en el mismo arreglo (in-place) mientras que Merge Sort crea arreglos auxiliares L y R en cada fusión, generando más operaciones de copia en memoria.

Quick Sort vs Insertion Sort
Quick Sort fue aproximadamente 900 veces más rápido que Insertion Sort. Esta diferencia refleja la brecha real entre O(n log n) y O(n²): con 100,000 elementos, Quick Sort realiza alrededor de 1,700,000 operaciones comparado con los ~5,000,000,000 de Insertion Sort.

¿Por qué Insertion Sort tardó tanto con strings?
A diferencia de comparar números enteros (una operación), comparar dos strings implica recorrer carácter por carácter. Con palabras promedio de 6-8 caracteres, cada comparación equivale a ~7 operaciones, multiplicando el tiempo total considerablemente.

10. Conclusiones

	•	Quick Sort es la mejor opción para datasets grandes de strings en la práctica. Su rendimiento in-place y su excelente uso del caché del procesador lo hacen superior a Merge Sort a pesar de tener la misma complejidad teórica.

	•	El uso de pivote aleatorio es esencial en Quick Sort. Sin él, un dataset parcialmente ordenado puede degradar su rendimiento de 223 ms a más de 3 minutos, como se observó al inicio del proyecto.

	•	Pasar vectores por referencia (&) es crítico en C++. El error de retornar el vector por valor en Quick Sort y Merge Sort causó que cada llamada recursiva copiara 100,000 strings, multiplicando el tiempo por más de 1,000x.

	•	Insertion Sort y Bubble Sort son viables solo para datasets pequeños (menos de 1,000 elementos) o arreglos casi ordenados. Para 100,000 strings, su complejidad O(n²) los hace completamente imprácticos.

	•	La separación del código en archivos .h y .cpp es fundamental para proyectos con múltiples algoritmos. Incluir directamente archivos .cpp genera errores de linkeo y definiciones duplicadas. El header declara la interfaz y el .cpp implementa la lógica.

	•	Medir tiempos con <chrono> sobre copias independientes del dataset es la única forma correcta de comparar algoritmos. Ordenar sobre el mismo vector sesga los resultados porque los algoritmos posteriores reciben datos ya ordenados, reduciendo artificialmente su tiempo de ejecución.
