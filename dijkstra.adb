with Ada.Text_IO;

procedure dijkstra is
  package T_IO renames Ada.Text_IO;
  -- Variables necesarias para el programa
  INT_MAX : constant Integer  := 999999;
  INF_SYMB: constant String   := "∞";
  type Grafo is array (Integer range <>, Integer range <>) of Integer;
  
  -- Subprocedimientos y funciones necesarias para el programa
  procedure dijkstra_fn(vertex_Number : in Integer; matriz_Grafo : in Grafo; vert_origen : in Integer) is
  
    --Variables del subprocedimiento
    distancia : array (0 .. vertex_Number) of Integer;
    visitado  : array (0 .. vertex_Number) of Integer;

  begin
    for i in matriz_Grafo'Range loop
      distancia(i):= INT_MAX;
      visitado(i) := 0;
    end loop;

    for i in 0 .. vertex_Number - 1 loop
      u   : Integer := 0;
      min : Integer := INT_MAX;

      for j in 0 .. vertex_Number loop
        if ((visitado(j) /= 1) and (distancia(j) < min)) then
          u   := j;
          min := distancia(j);
        end if;
      end loop;

      visitado(u) := 1;

      for j in 0 .. vertex_Number loop
        if visitado(j) /= 1 and matriz_Grafo(u,j) = 1 and distancia(u) < INT_MAX and (distancia(u)+matriz_Grafo(u,j)) < distancia(j) then
          distancia(j) := distancia(u) + matriz_Grafo(u,j);
        end if;  
      end loop;

      T_IO.Put("Vertice");T_IO.Put("  ");T_IO.Put_Line("Distancia desde el origen");
      for i in distancia'Range loop
        if distancia(i) /= INT_MAX then
          T_IO.Put(Integer'Image(i));T_IO.Put(" ");T_IO.Put_Line(Integer'Image(distancia(i)));
        else
          T_IO.Put(Integer'Image(i));T_IO.Put(" ");T_IO.Put_Line(INF_SYMB);
        end if;

      end loop;
    end loop;

    distancia(vert_origen) := 0;

  end dijkstra_fn;

begin
  n_vertices      : Integer;
  vertice_origen  : Integer;
  
  T_IO.Put("Ingrese la cantidad de vertices que tendrá el grafo: ");
  n_vertices := Integer'Value(T_IO.Get_Line);
  n_vertices := n_vertices - 1;
  T_IO.Put_Line("El número ingresado es: "&Integer'Image(n_vertices));
  
  matriz_Grafo  : Grafo(0 .. n_vertices, 0 .. n_vertices);

  for i in matriz_Grafo'Range loop
    for j in matriz_Grafo'Range loop
      T_IO.Put("Ingrese el dato de la matriz del grafo en la posición ("&Integer'Image(i)&" , "&Integer'Image(j)&"): ");
      matriz_Grafo(i,j) := Integer'Value(T_IO.Get_Line);
    end loop;
  end loop;

  T_IO.Put("Ingrese el vértice desde el que desea calcular la distancia: ");
  vertice_origen := Integer'Value(T_IO.Get_Line);
  --vertice_origen := vertice_origen - 1;

  dijkstra_fn(n_vertices, matriz_Grafo, vertice_origen);

end dijkstra;
