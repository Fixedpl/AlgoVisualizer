#include "AnimationChainBuilder.h"




AnimationChainBuilder::AnimationChainBuilder(Entity& entity) : m_entity(entity) {
	m_anim_chain = new AnimationChain();
}

AnimationChainBuilder& AnimationChainBuilder::move(std::function<float(float, const float&)>& tween,
	const float& duration, const glm::vec3& vec) {
	m_anim_chain->add({ m_entity, duration, 0.0f, vec, tween });
	return *this;
}

AnimationChainBuilder& AnimationChainBuilder::color(std::function<float(float, const float&)>& tween, 
	const float& duration, const glm::vec4& beg_color, const glm::vec4& end_color)
{
	m_anim_chain->add({ m_entity, duration, 0.0f, beg_color, end_color, tween });
	return *this;
}

AnimationChain* AnimationChainBuilder::build() {
	return m_anim_chain;
}
