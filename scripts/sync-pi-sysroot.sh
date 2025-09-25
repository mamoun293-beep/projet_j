#!/usr/bin/env bash
set -euo pipefail

PI_HOST="rpi"          # alias SSH
PI_USER="yanis"       # adapte si besoin
SYSROOT_DIR="$HOME/dev/projet_j/sysroot"

# Affiche un message propre si on interrompt (Ctrl-C)
trap 'echo -e "\n[!] Sync interrompue. Tu peux relancer, rsync reprendra là où c’est resté." >&2' INT TERM

mkdir -p "$SYSROOT_DIR"/{lib,usr/include,usr/lib,usr/local/include,usr/local/lib}

RSYNC="rsync -avP -L --delete --numeric-ids"

echo "[*] Sync /lib ..."
$RSYNC "$PI_USER@$PI_HOST:/lib/"               "$SYSROOT_DIR/lib/"

echo "[*] Sync /usr/include ..."
$RSYNC "$PI_USER@$PI_HOST:/usr/include/"       "$SYSROOT_DIR/usr/include/"

echo "[*] Sync /usr/lib ..."
$RSYNC "$PI_USER@$PI_HOST:/usr/lib/"           "$SYSROOT_DIR/usr/lib/"

echo "[*] Sync /usr/local/include (optionnel) ..."
$RSYNC "$PI_USER@$PI_HOST:/usr/local/include/" "$SYSROOT_DIR/usr/local/include/" || true

echo "[*] Sync /usr/local/lib (optionnel) ..."
$RSYNC "$PI_USER@$PI_HOST:/usr/local/lib/"     "$SYSROOT_DIR/usr/local/lib/" || true

echo "[✓] Sysroot synced to: $SYSROOT_DIR"