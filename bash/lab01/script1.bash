# Esercizio 1

cd;
echo $(pwd);
mkdir prova_dir;
chmod 750 prova_dir;
cd prova_dir;
touch root_list.txt;
ls / >> root_list.txt;
mv root_list.txt listato.txt;
touch listato3.txt;
head -n 3 listato.txt >> listato3.txt;