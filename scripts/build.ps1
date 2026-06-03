Write-Host "Compiling build files"
cmake -S . -B build -G Ninja

Write-Host "Compiling Project"
cmake --build build

Write-Host "Running Program"

# Start process and wait, which forwards Ctrl+C to the program
$proc = Start-Process -FilePath ".\build\voltTest\VoltTest.exe" -PassThru -Wait
Write-Host "Program finished with exit code:" $proc.ExitCode

# cmake --build build --target clean