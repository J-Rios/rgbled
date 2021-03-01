# Build Instructions

1. Make sure you have ESP-IDF installed and **IDF_PATH** correctly setup (go to esp-idf directory and run `. ./export.sh`).

2. Configure project to build for a specific target:

```bash
idf.py --preview set-target esp32c3
```

3. Launch build:

```bash
idf.py all
```

4. Flash the firmware:

```bash
# Just Flash
idf.py flash

# Flash and open Serial interface
idf.py flash monitor
```
