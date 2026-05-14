#include "Album.h"

Album::Album(int idAlb, int idArt, const std::string& tit, int a, float p, const std::string& form)
    : idAlbum(idAlb), idArtista(idArt), titulo(tit), ano(a), preco(p), formato(form) {}

int Album::getIdAlbum() const {
    return idAlbum;
}

float Album::getPreco() const {
    return preco;
}

std::string Album::getTitulo() const {
    return titulo;
}

std::string Album::getFormato() const {
    return formato;
}//
// Created by Guilherme Martins on 14/05/2026.
//