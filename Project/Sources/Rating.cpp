#include "../Rating.h"

int Rating::contadorIds = 1;

Rating::Rating(int idA, int pont) : idRating(contadorIds++), idAlbum(idA) {
    setPontuacao(pont);
}

void Rating::setPontuacao(int pont) {
    if (pont < 1 || pont > 5) {
        throw InvalidRatingException("Erro de Validação: A pontuação tem de ser entre 1 e 5 estrelas!");
    }
    pontuacao = pont;
}

int Rating::getPontuacao() const {
    return pontuacao;
}

int Rating::getIdAlbum() const {
    return idAlbum;
}

int Rating::getIdRating() const {
    return idRating;
}

std::string Rating::getEstrelasVisual() const {
    std::string visual = "";
    for(int i = 0; i < pontuacao; i++) visual += "*";
    for(int i = pontuacao; i < 5; i++) visual += "-";
    return visual;
}