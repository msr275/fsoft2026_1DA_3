#include "../../Headers/models/Album.h"
#include "../../Headers/models/Artista.h"

int Album::id_artista() const {
    if (artista != nullptr) {
        return artista->get_id_artista();
    }
    return 0;
}
