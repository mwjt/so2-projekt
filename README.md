# Projekt Systemy Operacyjne 2

Projekt typu kulki.

Aplikacja wielowątkowa na Linuxie. Wykorzystuje `pthreads` (`std::thread`). Grafika w `ncurses`.

## Opis etapów

### Tworzenie/kończenie wątków

Rozpoczynanie wątków i umieszczanie ich w vectorze. Na końcu działania iteracja przez vector i wywołanie `join()` na każdym `joinable()` wątku.

### Synchronizacja na mutexach

### Unikanie hotwaitu

### Wymagania

```
g++ ncurses
```

### Budowanie

```
make install
```

### Uruchamianie

```
./main
```
