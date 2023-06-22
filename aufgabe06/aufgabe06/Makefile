PACKAGES=lib bin

.PHONY: all clean

#Wird hier $$p die Variable p genommen
all clean:
		for p in $(PACKAGES) ; do \
				(cd $$p && $(MAKE) $@ ) ; \
				done

# Die dynamischen Bibliotheken müssen in Linux in der Umgebungsvariable LD_LIBRARY_PATH zugeordnet werden,
# damit die dynamische Bibliothek zur Laufzeit gefunden werden kann. Um permanenten Zugriff
# auf die dynamische Bibliothekt zu erhalten, kann man diese auch nach /usr/lib64 kopieren.
# Wir umgehen das aber indem wir statt einer fixen Zuordnung dem Programm über die Umgebungsvariable
# LD_LIBRARY_PATH beim Aufruf temporär mitteilen, wo sich die dynamische Bibliothek befindet.