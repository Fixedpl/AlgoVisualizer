#include "AnimationPlayer.h"

#include "BaseComponents.h"


void AnimationPlayer::play(const TransformAnimation& anim)
{
	m_transform_anims.emplace_back(anim);
}

void AnimationPlayer::play(const ColorAnimation& anim)
{
	m_color_anims.emplace_back(anim);
}

void AnimationPlayer::play(AnimationChain* anim_chain)
{
	std::vector<TransformAnimation>& transform_anims = anim_chain->getTransformAnims();
	m_transform_anims.insert(m_transform_anims.end(), transform_anims.begin(), transform_anims.end());

	std::vector<ColorAnimation>& color_anims = anim_chain->getColorAnims();
	m_color_anims.insert(m_color_anims.end(), color_anims.begin(), color_anims.end());
}

void AnimationPlayer::onUpdate(const float& dt)
{
	onUpdateTransform(dt);
	onUpdateColor(dt);
}

void AnimationPlayer::onUpdateTransform(const float& dt)
{
	int idx_to_remove = -1;
	for (int i = 0; i < m_transform_anims.size(); i++) {
		TransformAnimation& anim = m_transform_anims[i];
		if (anim.time >= anim.duration) {
			idx_to_remove = i;
			anim.time = anim.duration;
		}

		Transform& transform = anim.entity.get<Transform>();
		glm::vec3 dist = anim.vec * anim.func(std::max(anim.time, 0.0f), anim.duration);
		transform.pos = transform.pos + dist - anim.moved_by;
		anim.moved_by = dist;
		anim.time += dt;
	}

	if (idx_to_remove != -1) {
		m_transform_anims.erase(m_transform_anims.begin() + idx_to_remove);
	}
}

void AnimationPlayer::onUpdateColor(const float& dt)
{
	int idx_to_remove = -1;
	for (int i = 0; i < m_color_anims.size(); i++) {
		ColorAnimation& anim = m_color_anims[i];
		if (anim.time >= anim.duration) {
			idx_to_remove = i;
			anim.time = anim.duration;
		}

		Color& color = anim.entity.get<Color>();
		float v = anim.func(std::max(anim.time, 0.0f), anim.duration);
		color.col = (1.0f - v) * anim.beg_color + v * anim.end_color;
		anim.time += dt;
	}

	if (idx_to_remove != -1) {
		m_color_anims.erase(m_color_anims.begin() + idx_to_remove);
	}
}
