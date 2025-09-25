set -euo pipefail
PI_HOST="rpi"
PI_USER="yanis"

#à modifier selon la version à envoyer et le binaire
BIN="$HOME/dev/projet_j/build/arm64/Debug/two_sum"
DEST="/home/$PI_USER/projet_j_bin"

scp "$BIN" "$PI_USER@$PI_HOST:$DEST"
ssh "$PI_USER@$PI_HOST" "chmod +x $DEST && echo '--- Running on Pi ---' && $DEST"
