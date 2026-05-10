g++ main.cpp core/*.cpp ui/*.cpp utils/*.cpp -o LetterCards

if [ $? -ne 0 ]; then
    echo "Compilation Failed."
    exit 1
fi

echo "Compilation Completed."
echo
read -p "Do you want to run the game? (y/n): " run

if [ "$run" = "y" ] || [ "$run" = "Y" ]; then
    echo "Running the Game..."
    ./LetterCards
else
    echo "Exiting..."
fi