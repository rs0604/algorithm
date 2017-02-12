-- TODO : 標準入力から配列の値を受け取るようにする


function arrayprint(array, arraySize)
   for i = 1, arraySize, 1 do
      io.write(array[i])
      io.write(" ")
   end
   print("")
end



function insertionSort(array, arraySize)
   for i = 2, arraySize -1, 1 do
      tempval = array[i]
      j = i - 1
      while j >= 1 and array[j] > tempval do
         array[j+1] = array[j]
         j = j - 1
         arrayprint(array, arraySize)
      end
      array[j+1] = tempval
      arrayprint(array, arraySize)
   end
end

-- Main --
array = {1, 6, 2, 5, 7, 4, 3}
arraySize = 5

print("処理前")
arrayprint(array, arraySize)
print("処理開始")
insertionSort(array, arraySize)

