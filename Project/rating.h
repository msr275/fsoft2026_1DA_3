#ifndef FSOFT2026_1DA_3_RATING_H
#define FSOFT2026_1DA_3_RATING_H

#include <string>
#include <stdexcept>

class InvalidRatingException : public std::invalid_argument {
public:
    explicit InvalidRatingException(const std::string& message)
        : std::invalid_argument(message) {}
};

class Rating {
private:
    static int contadorIds;

    int idRating;
    int idAlbum;
    int pontuacao;

public:
    Rating(int idA, int pont);

    void setPontuacao(int pont);
    int getPontuacao() const;
    int getIdAlbum() const;
    int getIdRating() const;
    std::string getEstrelasVisual() const;
};

#endif