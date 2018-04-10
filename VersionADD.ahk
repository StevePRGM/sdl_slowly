Loop
{
 ifExist, versions/main_ vD%A_Index%.cpp
 {
  continue
  tooltip, versions/main_ vD%A_Index%.cpp
 } else {
  FileCopy, main.cpp, versions/main_ vD%A_Index%.cpp, 0
  tooltip, main.cpp`r`n=== TO ===`r`nversions/main_ vD%A_Index%.cpp
  break
 }
}
sleep, 3000