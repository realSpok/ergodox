inotifywait -m -r -q  --format '%w' ./keymap.c
do
	  #echo "something happened on path $FILE"
	  ../../load
done
