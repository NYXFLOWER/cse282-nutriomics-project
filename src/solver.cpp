#include "solver.h"

#include "scoring.h"

#include <limits>
#include <queue>
#include <utility>
#include <vector>

std::vector<Treatment> BaseSolver::findTreatments(const PatientList& ps)
{
    std::vector<Treatment> treatments;
    for (const auto& p : ps.patients) {
        treatments.emplace_back(this->findTreatment(p));
    }
    return treatments;
}

Treatment BruteForceSolver::findTreatment(const Patient& p)
{
    Treatment t(this->nim.nutrient_size);
    std::queue<std::pair<Treatment, int>> q;
    q.push({ t, 0 });
    double best_distance = std::numeric_limits<double>::infinity();
    Treatment best_solution = t;

    while (!q.empty()) {
        auto& [t_front, depth] = q.front();
        q.pop();
        auto qualifier_hat = compute_qualifier(this->nim.impact_matrix_arma, t_front.treat_vector_arma);
        auto distance = compute_distance(p.qualifier_arma, qualifier_hat);
        if (distance < best_distance) {
            best_distance = distance;
            best_solution = t_front;
        }
        if (depth + 1 > this->k) {
            continue;
        }
        for (auto i = 0; i < t_front.treat_vector.size(); i++) {
            if (t_front.treat_vector[i] == 1) {
                continue;
            }
            auto t_next = t_front.flip(i);
            q.push({ t_next, depth + 1 });
        }
    }

    return best_solution;
}

Treatment ProposedSolver::findTreatment(const Patient& p)
{
    Treatment t(this->nim.nutrient_size);
    return t;
}