#pragma once

class Cercle;
class Polygone;
class Segment;
class Triangle;
class Groupe;

class ModificateurForme {
    public:
        /**
         * @brief Modifie un cercle
         * @param cercle Cercle
         */
        virtual void modifier(Cercle* cercle) const = 0;

        /**
         * @brief Modifie un polygone
         * @param polygone Polygone
         */
        virtual void modifier(Polygone* polygone) const = 0;

        /**
         * @brief Modifie un segment
         * @param segment Segment
         */
        virtual void modifier(Segment* segment) const = 0;

        /**
         * @brief Modifie un triangle
         * @param triangle Triangle
         */
        virtual void modifier(Triangle* triangle) const = 0;

        /**
         * @brief Modifie un groupe
         * @param groupe Groupe
         */
        virtual void modifier(Groupe* groupe) const = 0;
};